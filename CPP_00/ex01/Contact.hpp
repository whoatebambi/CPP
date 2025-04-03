/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcouserg <fcouserg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:05:10 by fcouserg          #+#    #+#             */
/*   Updated: 2024/11/23 17:22:00 by fcouserg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

typedef std::string str;

class Contact
{
	public:
			Contact();
			~Contact();
			void	set_first_name(str name);
			void	set_last_name(str name);
			void	set_nickname(str name);
			void	set_phone(str name);
			void	set_secret(str name);
			str		get_first_name() const;
			str		get_last_name() const;
			str		get_nickname() const;
			str		get_phone() const;
			str		get_secret() const;

	private:
			str		_first_name;
			str		_last_name;
			str		_nickname;
			str		_phone;
			str		_secret;
};

#endif
